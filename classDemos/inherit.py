class LogicGate:
    def __init__(self, n):
        self.label = n
        self.output = None

    def getLabel(self):
        return self.label

    def getOutput(self):
        self.output = self.performGateLogic()
        return self.output


class BinaryGate(LogicGate):
    def __init__(self, n):
        super().__init__(n)
        self.pinA = None
        self.pinB = None

    def getPinA(self):
        return self.pinA if isinstance(self.pinA, int) else self.pinA.getFrom().getOutput()

    def getPinB(self):
        return self.pinB if isinstance(self.pinB, int) else self.pinB.getFrom().getOutput()

    def setNextPin(self, source):
        if self.pinA is None:
            self.pinA = source
        elif self.pinB is None:
            self.pinB = source
        else:
            raise RuntimeError("Error: NO EMPTY PINS")


class UnaryGate(LogicGate):
    def __init__(self, n):
        super().__init__(n)
        self.pin = None

    def getPin(self):
        return self.pin if isinstance(self.pin, int) else self.pin.getFrom().getOutput()

    def setNextPin(self, source):
        if self.pin is None:
            self.pin = source
        else:
            raise RuntimeError("Error: NO EMPTY PIN!")


class AndGate(BinaryGate):
    def performGateLogic(self):
        return 1 if self.getPinA() == 1 and self.getPinB() == 1 else 0


class OrGate(BinaryGate):
    def performGateLogic(self):
        return 1 if self.getPinA() == 1 or self.getPinB() == 1 else 0


class NotGate(UnaryGate):
    def performGateLogic(self):
        return 0 if self.getPin() == 1 else 1


class NandGate(AndGate):
    def performGateLogic(self):
        return 0 if super().performGateLogic() == 1 else 1


class NorGate(OrGate):
    def performGateLogic(self):
        return 0 if super().performGateLogic() == 1 else 1


class XorGate(BinaryGate):
    def performGateLogic(self):
        return 1 if self.getPinA() != self.getPinB() else 0


class Connector:
    def __init__(self, fgate, tgate):
        self.fromgate = fgate
        self.togate = tgate
        tgate.setNextPin(self)

    def getFrom(self):
        return self.fromgate


def test_circuit(inputs):
    
    g1 = AndGate("G1")
    g2 = OrGate("G2")
    g3 = XorGate("G3")  # More useful in a 4-bit circuit
    g4 = NotGate("G4")

    # Assign inputs correctly
    g1.pinA, g1.pinB = inputs[0], inputs[1]
    g2.pinA, g2.pinB = inputs[2], inputs[3]

    # Connect outputs properly
    c1 = Connector(g1, g3)
    c2 = Connector(g2, g3)
    c3 = Connector(g3, g4)

    return g4.getOutput()


def generate_truth_table():
    inputs = [(a, b, c, d) for a in [0, 1] for b in [0, 1] for c in [0, 1] for d in [0, 1]]

    print("Truth Table:")
    print("A B C D | Output")
    print("--------|-------")
    for inp in inputs:
        output = test_circuit(inp)
        print(f"{inp[0]} {inp[1]} {inp[2]} {inp[3]} | {output}")


if __name__ == "__main__":
    generate_truth_table()
