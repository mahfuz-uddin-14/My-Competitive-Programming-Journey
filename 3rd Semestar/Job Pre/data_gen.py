import pandas as pd
import random

educations = ['HSC', 'B.Sc', 'M.Sc', 'Diploma', 'BBA', 'MBA', 'PhD']
backgrounds = ['Science', 'Commerce', 'Arts', 'CSE', 'EEE', 'Business', 'Statistics']

broad_skills = [
    'Data Science & AI', 
    'Software Development', 
    'Cyber Security', 
    'Creative & Business'
]

data = []

for _ in range(300):
    edu = random.choice(educations)
    bg = random.choice(backgrounds)
    
    if bg in ['CSE', 'EEE', 'Statistics']:
        target_skill = random.choices(
            broad_skills, 
            weights=[40, 40, 15, 5], 
            k=1
        )[0]
    elif bg == 'Science':
        target_skill = random.choices(
            broad_skills, 
            weights=[30, 30, 20, 20], 
            k=1
        )[0]
    elif bg in ['Commerce', 'Business', 'Arts']:
        target_skill = random.choices(
            broad_skills, 
            weights=[10, 10, 5, 75], 
            k=1
        )[0]

    if target_skill in ['Data Science & AI', 'Software Development', 'Cyber Security']:
        math = random.randint(7, 10) 
        prog = random.randint(6, 10)
    else:
        math = random.randint(3, 7)
        prog = random.randint(2, 6)
    
    eng = random.randint(5, 9)

    if bg == 'Arts':
        eng = random.randint(8, 10)

    if target_skill == 'Data Science & AI':
        intr = random.choice(['Research', 'Statistics', 'Math', 'AI'])
    elif target_skill == 'Software Development':
        intr = random.choice(['Coding', 'Problem Solving', 'Building Apps'])
    elif target_skill == 'Cyber Security':
        intr = random.choice(['Hacking', 'Networks', 'Security'])
    else:
        intr = random.choice(['Design', 'Writing', 'Management', 'Communication'])

    data.append([edu, bg, intr, math, prog, eng, target_skill])

# dataframe
df = pd.DataFrame(data, columns=['education', 'background', 'interest', 'math', 'programming', 'english', 'recommended_skill'])

# CSV Save
df.to_csv('career_dataset.csv', index=False)

print("Dataset generated with 4 broad classes to reduce sparsity.")
print(df['recommended_skill'].value_counts()) # class Distri
print("\nSample Data:")
print(df.head())