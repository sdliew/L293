class L293D {
  int EnablePin;
  int FirstPin;
  int SecondPin;
  int Speed = 0;

  public:
    L293D(int enablePin, int firstPin);
    L293D(int enablePin, int firstPin, int secondPin);  /* L293D Constructor */
    void Stop();
    void Forward();
    void Reverse();
    int GetSpeed();
    void SetSpeed(int Speed);
};
