import pandas as pd
import numpy as np
import pickle

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# =====================
# Load Dataset
# =====================
df = pd.read_csv("career_dataset.csv")

# Features & Target
X = df.drop("recommended_skill", axis=1)
y = df["recommended_skill"]

# =====================
# Column Types
# =====================
cat_cols = ["education", "background", "interest"]
num_cols = ["math", "programming", "english"]

# =====================
# Preprocessing
# =====================
preprocessor = ColumnTransformer(
    transformers=[
        ("cat", OneHotEncoder(handle_unknown="ignore"), cat_cols),
        ("num", "passthrough", num_cols)
    ]
)

# =====================
# Model
# =====================
model = RandomForestClassifier(
    n_estimators=200,
    max_depth=12,
    random_state=42
)

# =====================
# Pipeline
# =====================
pipeline = Pipeline(steps=[
    ("preprocessor", preprocessor),
    ("model", model)
])

# =====================
# Train-Test Split
# =====================
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# =====================
# Train
# =====================
pipeline.fit(X_train, y_train)

# =====================
# Evaluation
# =====================
y_pred = pipeline.predict(X_test)

acc = accuracy_score(y_test, y_pred)
print("Accuracy:", acc)
print("\nClassification Report:\n")
print(classification_report(y_test, y_pred))
print("\nConfusion Matrix:\n")
print(confusion_matrix(y_test, y_pred))

# =====================
# Save Model
# =====================
with open("career_recommendation_model.pkl", "wb") as f:
    pickle.dump(pipeline, f)

print("\n✅ Model saved as career_recommendation_model.pkl")
