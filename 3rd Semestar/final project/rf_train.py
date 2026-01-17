import pandas as pd
import numpy as np
import pickle

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report

# Load dataset
df = pd.read_csv("diabetes.csv")

# Handle missing values
cols_with_zero = ['Glucose','BloodPressure','SkinThickness','Insulin','BMI']
df[cols_with_zero] = df[cols_with_zero].replace(0, np.nan)

# Features & target
X = df.drop('Outcome', axis=1)
y = df['Outcome']

# Preprocessing pipeline
preprocessor = Pipeline([
    ('imputer', SimpleImputer(strategy='median')),
    ('scaler', StandardScaler())
])

# Model
model = RandomForestClassifier(
    n_estimators=200,
    max_depth=10,
    random_state=42,
    n_jobs=-1
)

pipeline = Pipeline([
    ('preprocessor', preprocessor),
    ('model', model)
])

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# Train model
pipeline.fit(X_train, y_train)

# Evaluation
y_pred = pipeline.predict(X_test)
acc = accuracy_score(y_test, y_pred)

print("Accuracy:", acc)
print(classification_report(y_test, y_pred))

# Save model
with open("diabetes_rf_pipeline.pkl", "wb") as f:
    pickle.dump(pipeline, f)

print("Model saved as diabetes_rf_pipeline.pkl")
