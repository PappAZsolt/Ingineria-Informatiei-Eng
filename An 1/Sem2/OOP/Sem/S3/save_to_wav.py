import numpy as np
from scipy.io.wavfile import write
import argparse

def save_to_wav(csv_filepath, wav_filepath, sample_rate=44100):
    samples = np.loadtxt(csv_filepath)
    # normalize to 16 bit
    samples = np.clip(samples, -1.0, 1.0)
    samples = np.int16(samples * 32767)

    write(wav_filepath, sample_rate, samples)
    print(f"WAV file saved to {wav_filepath}")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Convert a CSV of samples to a WAV file.")
    parser.add_argument('--input', '-i', type=str, required=True, help='Path to input CSV file')
    parser.add_argument('--output', '-o', type=str, required=True, help='Path to output WAV file')
    parser.add_argument('--rate', '-r', type=int, default=44100, help='Sample rate in Hz (default: 44100)')

    args = parser.parse_args()

    save_to_wav(args.input, args.output, args.rate)
