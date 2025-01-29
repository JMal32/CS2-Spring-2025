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


class Connector:
    def __init__(self, fgate, tgate):
        self.fromgate = fgate
        self.togate = tgate
        tgate.setNextPin(self)

    def getFrom(self):
        return self.fromgate

    def getTo(self):
        return self.togate


def main():
    g1 = AndGate("G1")  
    g2 = AndGate("G2")
    g3 = OrGate("G3")  
    g4 = NotGate("G4") 
    c1 = Connector(g1, g3)
    c2 = Connector(g2, g3)
    c3 = Connector(g3, g4)

    print(f"Final Output: {g4.getOutput()}")  

if __name__ == "__main__":
    main()
