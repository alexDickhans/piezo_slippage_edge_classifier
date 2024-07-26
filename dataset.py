from torch.utils.data import Dataset
import os
import numpy as np
import torch

class PiezoDataset(Dataset):
    def __init__(self, data_file):
        self.data = np.loadtxt(data_file, delimiter=",", dtype=np.float32)

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        return torch.from_numpy(self.data[idx][1:]), self.data[idx][0]
