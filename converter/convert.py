from aifes import pytorch2aifes
from model import PiezoClassifier
import torch

model = PiezoClassifier()
model.load_state_dict(torch.load('../model.pth'))

pytorch2aifes.convert_to_fnn_f32_express(model, 'test.c')
