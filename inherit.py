class LogicGate:
    def __init__(self, n):
        self.label = n
        self.output = None  # Fixed 'none' to 'None'

    def getLabel(self):
        return self.label

    def getOutput(self):
        self.output = self.performGateLogic()  # Call the function
        return self.output


class BinaryGate(LogicGate):
    def __init__(self, n):
        super().__init__(n)
        self.pinA = None
        self.pinB = None

    def getPinA(self):
        if self.pinA is None:
            return int(input(f"Enter Pin A input for gate {self.getLabel()} --> "))
        else:
            return self.pinA.getFrom().getOutput()

    def getPinB(self):
        if self.pinB is None:
            return int(input(f"Enter Pin B input for gate {self.getLabel()} --> "))
        else:
            return self.pinB.getFrom().getOutput()

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
        return int(input(f"Enter Pin input for gate {self.getLabel()} --> "))

    def setNextPin(self, source):
        if self.pin is None:
            self.pin = source
        else:
            raise RuntimeError("Error: NO EMPTY PIN!")


class AndGate(BinaryGate):
    def __init__(self, n):
        super().__init__(n)

    def performGateLogic(self):
        a = self.getPinA()
        b = self.getPinB()
        return 1 if a == 1 and b == 1 else 0


class OrGate(BinaryGate):
    def __init__(self, n):
        super().__init__(n)

    def performGateLogic(self):
        a = self.getPinA()
        b = self.getPinB()
        return 1 if a == 1 or b == 1 else 0


class NotGate(UnaryGate):
    def __init__(self, n):
        super().__init__(n)

    def performGateLogic(self):
        a = self.getPin()
        return 0 if a == 1 else 1


# Part C: Adding NAND, NOR, XOR Gates
class NandGate(AndGate):
    def performGateLogic(self):
        return 0 if super().performGateLogic() == 1 else 1


class NorGate(OrGate):
    def performGateLogic(self):
        return 0 if super().performGateLogic() == 1 else 1


class XorGate(BinaryGate):
    def __init__(self, n):
        super().__init__(n)

    def performGateLogic(self):
        a = self.getPinA()
        b = self.getPinB()
        return 1 if a != b else 0


class Connector:
    def __init__(self, fgate, tgate):
        self.fromgate = fgate
        self.togate = tgate
        tgate.setNextPin(self)

    def getFrom(self):
        return self.fromgate

    def getTo(self):
        return self.togate


# Updated main function with a test circuit
def main():
    g1 = AndGate("G1")  
    g2 = OrGate("G2")
    g3 = NandGate("G3")  # Added NAND gate
    g4 = NorGate("G4")   # Added NOR gate
    g5 = XorGate("G5")   # Added XOR gate
    g6 = NotGate("G6")

    c1 = Connector(g1, g3)
    c2 = Connector(g2, g3)
    c3 = Connector(g3, g4)
    c4 = Connector(g4, g5)
    c5 = Connector(g5, g6)

    print(f"Final Output: {g6.getOutput()}")  # Display result


if __name__ == "__main__":
    main()
