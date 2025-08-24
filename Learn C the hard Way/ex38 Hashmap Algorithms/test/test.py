# To analyze the distribution of the various algorithms
import pandas as pd

df = pd.read_csv("test.csv")

print(df.describe())