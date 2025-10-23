#ifndef __COLOR__
    #define __COLOR__

class Color {
    public:
        enum ColorCode {
            R = 0,
            G,
            B,
            A
        };

        Color();
        Color(double r, double g, double b, double a = 255);
        Color(const Color &otherColor);
        ~Color() = default;
        void change(Color::ColorCode colorCode, double newColorCode);
        double get(Color::ColorCode colorCode) const;
        void clamp();
        void operator=(const Color &otherColor);
        bool operator==(const Color &otherColor) const;
        bool operator!=(const Color &otherColor) const;
        Color operator+(const Color &otherColor) const;
        void operator+=(const Color &otherColor);
        Color operator-(const Color &otherColor) const;
        void operator-=(const Color &otherColor);
        Color operator*(const Color &otherColor) const;
        Color operator*(double value) const;
        void operator*=(const Color &otherColor);
        void operator*=(double value);
        Color operator/(const Color &otherColor) const;
        Color operator/(double value) const;
        void operator/=(const Color &otherColor);
        void operator/=(double value);
    private:
        double _r;
        double _g;
        double _b;
        double _a;
};

#endif
