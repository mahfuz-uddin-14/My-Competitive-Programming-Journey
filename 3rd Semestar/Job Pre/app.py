import gradio as gr
import pandas as pd
import pickle

# =====================
# Load trained model
# =====================
with open("career_recommendation_model.pkl", "rb") as f:
    model = pickle.load(f)

# =====================
# Prediction Function
# =====================
def predict_career(education, background, interest, math, programming, english):
    df = pd.DataFrame({
        "education": [education],
        "background": [background],
        "interest": [interest],
        "math": [math],
        "programming": [programming],
        "english": [english]
    })

    pred = model.predict(df)[0]

    tips = {
        "Software Development": "💻 Focus on coding, algorithms, and real-world projects.",
        "Data Science & AI": "📊 Improve math, statistics, Python, and machine learning.",
        "Cyber Security": "🔐 Learn networking, security fundamentals, and ethical hacking.",
        "Creative & Business": "🎨 Improve communication, creativity, and business skills."
    }

    return pred, tips[pred]

# =====================
# Gradio Interface (v3.x)
# =====================
interface = gr.Interface(
    fn=predict_career,
    inputs=[
        gr.Dropdown(
            ["HSC", "Diploma", "BBA", "B.Sc", "MBA", "M.Sc", "PhD"],
            label="🎓 Education Level"
        ),
        gr.Dropdown(
            ["Science", "Commerce", "Arts", "CSE", "EEE", "Business", "Statistics"],
            label="📚 Academic Background"
        ),
        gr.Dropdown(
            [
                "Coding",
                "Problem Solving",
                "Building Apps",
                "AI",
                "Hacking",
                "Design",
                "Communication",
                "Writing",
                "Networks",
                "Statistics",
                "Research",
                "Management"
            ],
            label="❤️ Primary Interest"
        ),
        gr.Slider(1, 10, step=1, label="📐 Math Skill"),
        gr.Slider(1, 10, step=1, label="💻 Programming Skill"),
        gr.Slider(1, 10, step=1, label="🗣️ English Proficiency")
    ],
    outputs=[
        gr.Textbox(label="✅ Recommended Career Path"),
        gr.Textbox(label="📌 Career Guidance")
    ],
    title="🎯 ML-Based Career Recommendation System",
    description="A Machine Learning system that recommends suitable career domains based on student profile."
)

# =====================
# Launch App
# =====================
interface.launch(share=True)
