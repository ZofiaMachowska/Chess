#pragma once

class aiOptions {
private:
    bool firstPlayerAi;  
    bool secondPlayerAi;  

public:
    aiOptions();
    void setFirstPlayerAi(bool value);
    void setSecondPlayerAi(bool value);
    bool getFirstPlayerAi() const;
    bool getSecondPlayerAi() const;
};
