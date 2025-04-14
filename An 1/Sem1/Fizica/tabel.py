import pandas as pd
import matplotlib.pyplot as plt


data_semiconductor = {
    "Temperatura (°C)": [15, 19, 23, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74, 78, 82, 86],
    "Rezistenta (Ω)": [775, 655, 560, 500, 420, 360, 310, 264, 238, 207, 181, 156, 138, 121, 107, 95, 84, 75, 66]
}
data_metal = {
    "Temperatura (°C)": [39, 42, 45, 50, 55, 59, 63, 66, 70, 74, 77, 81, 85, 90, 94],
    "Rezistenta (Ω)": [2.9, 3.1, 3.1, 3.2, 3.3, 3.4, 3.4, 3.5, 3.6, 3.6, 3.7, 3.8, 3.8, 3.9, 4.0]
}

df_semiconductor = pd.DataFrame(data_semiconductor)
df_metal = pd.DataFrame(data_metal)

plt.figure(figsize=(10, 6))
plt.plot(df_semiconductor["Temperatura (°C)"], df_semiconductor["Rezistenta (Ω)"], marker='o', label="Semiconductor")
plt.plot(df_metal["Temperatura (°C)"], df_metal["Rezistenta (Ω)"], marker='s', label="Metal")

plt.title("Dependenta de temperatura a rezistivitatii electrice", fontsize=14)
plt.xlabel("Temperatura (°C)", fontsize=12)
plt.ylabel("Rezistenta (Ω)", fontsize=12)
plt.legend()
plt.grid(True)
plt.savefig('/mnt/data/Figura1_dependenta_rezistenta.png')
plt.show()
