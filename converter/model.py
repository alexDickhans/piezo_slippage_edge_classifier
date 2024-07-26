from torch import nn

class PiezoClassifier(nn.Module):
    def __init__(self):
        super(PiezoClassifier, self).__init__()

        self.network = nn.Sequential(
            nn.Linear(200, 64),
            nn.ReLU(),
            nn.Linear(64, 32),
            nn.ReLU(),
            nn.Linear(32, 1),
            nn.Sigmoid()
        )

    def forward(self, x):
        return self.network(x)
