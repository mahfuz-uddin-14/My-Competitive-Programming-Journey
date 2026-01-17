import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
import pickle

from sklearn.model_selection import train_test_split, cross_val_score, GridSearchCV
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.impute import SimpleImputer
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

import warnings
warnings.filterwarnings("ignore")

# ==========================================
# Task 1: Data Loading
# ==========================================
# আপনার আপলোড করা ফাইলটি Colab-এ আপলোড করে নাম দিন 'diabetes.csv'
df = pd.read_csv('diabetes.csv')

print("First 5 rows:")
print(df.head())
print(f"\nShape of the dataset: {df.shape}")

# ==========================================
# Task 2: Data Preprocessing (5 Steps)
# ==========================================

# Step 1: Handling Invalid Zeros (0 -> NaN)
# গ্লুকোজ, প্রেসার ইত্যাদির মান ০ হতে পারে না
cols_missing = ['Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI']
df[cols_missing] = df[cols_missing].replace(0, np.nan)

# Step 2: Feature Engineering (Age Grouping)
# বয়সকে ৩টি ভাগে ভাগ করা (Young, Middle, Senior)
df['Age_Group'] = pd.cut(df['Age'], bins=[0, 30, 50, 150], labels=[0, 1, 2]) # 0=Young, 1=Middle, 2=Senior

# Step 3: Imputation (Missing Value Handling)
# মিডিয়ান দিয়ে নাল ভ্যালু পূরণ করা
imputer = SimpleImputer(strategy='median')
df_imputed = pd.DataFrame(imputer.fit_transform(df), columns=df.columns)

# Step 4: Outlier Detection & Removal (IQR Method)
# আউটলাইয়ার রিমুভ করা যাতে মডেল ভালো কাজ করে
Q1 = df_imputed.quantile(0.25)
Q3 = df_imputed.quantile(0.75)
IQR = Q3 - Q1
df_clean = df_imputed[~((df_imputed < (Q1 - 1.5 * IQR)) | (df_imputed > (Q3 + 1.5 * IQR))).any(axis=1)]

print(f"\nOriginal Shape: {df.shape}")
print(f"Shape after Cleaning: {df_clean.shape}")

# ফিচার এবং টার্গেট আলাদা করা
X = df_clean.drop('Outcome', axis=1)
y = df_clean['Outcome']

# ==========================================
# Task 3: Pipeline Creation
# ==========================================
# Step 5: Scaling (StandardScaler) - পাইপলাইনের ভেতরে
# নিউমেরিক্যাল ডেটা স্কেলিং করা
preprocessor = Pipeline(steps=[
    ('scaler', StandardScaler())
])

# মডেল পাইপলাইন
model_pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('model', RandomForestClassifier(random_state=42))
])

# ==========================================
# Task 4, 5, 6: Selection, Training, CV
# ==========================================
# Train-Test Split (80% Train, 20% Test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

# Training
model_pipeline.fit(X_train, y_train)
print("\nModel Training Complete.")

# Cross-Validation
cv_scores = cross_val_score(model_pipeline, X_train, y_train, cv=5, scoring='accuracy')
print(f"\nCV Average Accuracy: {cv_scores.mean():.4f} (+/- {cv_scores.std():.4f})")

# ==========================================
# Task 7 & 8: Hyperparameter Tuning & Selection
# ==========================================
param_grid = {
    'model__n_estimators': [50, 100, 200],
    'model__max_depth': [None, 10, 20],
    'model__min_samples_split': [2, 5]
}

grid = GridSearchCV(model_pipeline, param_grid, cv=5, scoring='accuracy', n_jobs=-1)
grid.fit(X_train, y_train)

best_model = grid.best_estimator_
print(f"\nBest Parameters: {grid.best_params_}")
print(f"Best Accuracy: {grid.best_score_:.4f}")

# ==========================================
# Task 9: Evaluation
# ==========================================
y_pred = best_model.predict(X_test)

print("\n--- Test Set Evaluation ---")
print(f"Accuracy: {accuracy_score(y_test, y_pred):.4f}")
print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# Confusion Matrix
plt.figure(figsize=(6,4))
sns.heatmap(confusion_matrix(y_test, y_pred), annot=True, fmt='d', cmap='Blues')
plt.title("Confusion Matrix")
plt.show()

# ==========================================
# Save Model (For Task 11)
# ==========================================
with open("diabetes_model.pkl", "wb") as f:
    pickle.dump(best_model, f)
print("\n✅ Model saved as 'diabetes_model.pkl'. Download this file for Hugging Face.")