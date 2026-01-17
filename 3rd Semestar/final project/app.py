# gradio app

import gradio as gr
import pandas as pd
import pickle
import numpy as np

# 1. Load the Model
with open("diabetes_rf_pipeline.pkl", "rb") as f:
    model = pickle.load(f)

# 2. The Logic Function
def predict_diabetes(
    pregnancies, glucose, bp, skin,
    insulin, bmi, dpf, age
):
    input_df = pd.DataFrame([[ 
        pregnancies, glucose, bp, skin,
        insulin, bmi, dpf, age
    ]],
    columns=[
        'Pregnancies',
        'Glucose',
        'BloodPressure',
        'SkinThickness',
        'Insulin',
        'BMI',
        'DiabetesPedigreeFunction',
        'Age'
    ])

    # Predict
    prediction = model.predict(input_df)[0]

    # Return formatted result
    return "Diabetic" if prediction == 1 else "Non-Diabetic"

# 3. The App Interface
inputs = [
    gr.Slider(0, 20, step=1, label="Number of Pregnancies"),
    gr.Slider(50, 200, step=1, label="Glucose Level (mg/dL)"),
    gr.Slider(40, 130, step=1, label="Blood Pressure (mm Hg)"),
    gr.Slider(0, 100, step=1, label="Skin Thickness (mm)"),
    gr.Slider(0, 900, step=1, label="Insulin Level"),
    gr.Slider(10, 70, step=0.1, label="Body Mass Index (BMI)"),
    gr.Slider(0.0, 2.5, step=0.01, label="Diabetes Pedigree Function"),
    gr.Number(label="Age")
]
app = gr.Interface(
    fn=predict_diabetes,
    inputs=inputs,
    outputs="text",
    title="Diabetes Prediction System"
)

app.launch(share=True)
