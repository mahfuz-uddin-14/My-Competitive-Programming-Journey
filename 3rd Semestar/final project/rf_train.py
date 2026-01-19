import pandas as pd
import numpy as np
import pickle

from sklearn.model_selection import train_test_split, cross_val_score, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report

# 1. Load dataset
df = pd.read_csv("diabetes.csv")

# 2. Data Preprocessing 

# Step 1: Remove Duplicates
df.drop_duplicates(inplace=True)

# Step 2: Handle Invalid Zeros
cols_with_zero = ['Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI']
df[cols_with_zero] = df[cols_with_zero].replace(0, np.nan)

# Step 3: Imputation
imputer = SimpleImputer(strategy='median')
df = pd.DataFrame(imputer.fit_transform(df), columns=df.columns)

# Step 4: Outlier Handling
features = df.drop('Outcome', axis=1)
Q1 = features.quantile(0.25)
Q3 = features.quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR

condition = ((features >= lower_bound) & (features <= upper_bound)).all(axis=1)
df = df[condition]

# Step 5: Feature & Target Split
X = df.drop('Outcome', axis=1)
y = df['Outcome']

# 3. Pipeline & Model

# Preprocessing pipeline 
pipeline = Pipeline([
    ('scaler', StandardScaler()),
    ('model', RandomForestClassifier(random_state=42))
])

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# 4. Cross-Validation & Tuning

# Cross Validation check
cv_scores = cross_val_score(pipeline, X_train, y_train, cv=5, scoring='accuracy')


# Hyperparameter Tunin 
param_grid = {
    'model__n_estimators': [50, 100, 200],
    'model__max_depth': [None, 10, 20],
    'model__min_samples_split': [2, 5]
}

grid = GridSearchCV(pipeline, param_grid, cv=5, scoring='accuracy', n_jobs=-1)
grid.fit(X_train, y_train)

# Best Model Selection
best_model = grid.best_estimator_

# 5. Evaluation & Saving

# Evaluation
y_pred = best_model.predict(X_test)
acc = accuracy_score(y_test, y_pred)

print("\nTest Accuracy:", acc)
print(classification_report(y_test, y_pred))

# Save model
with open("diabetes_model.pkl", "wb") as f:
    pickle.dump(best_model, f)

print("Model saved")