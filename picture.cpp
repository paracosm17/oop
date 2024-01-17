#include <iostream>
#include <fstream>
#include <vector>

class SvgElement {
public:
    virtual std::string toSvg() const = 0;
};

class Circle : public SvgElement {
public:
    Circle(float cx, float cy, float r, const std::string& fill)
        : cx(cx), cy(cy), r(r), fill(fill) {}

    std::string toSvg() const override {
        return "<circle cx='" + std::to_string(cx) + "' cy='" + std::to_string(cy) +
               "' r='" + std::to_string(r) + "' fill='" + fill + "' />";
    }

private:
    float cx, cy, r;
    std::string fill;
};

class Rect : public SvgElement {
public:
    Rect(float x, float y, float width, float height, const std::string& fill)
        : x(x), y(y), width(width), height(height), fill(fill) {}

    std::string toSvg() const override {
        return "<rect x='" + std::to_string(x) + "' y='" + std::to_string(y) +
               "' width='" + std::to_string(width) + "' height='" + std::to_string(height) +
               "' fill='" + fill + "' />";
    }

private:
    float x, y, width, height;
    std::string fill;
};

class Line : public SvgElement {
public:
    Line(float x1, float y1, float x2, float y2, float width, const std::string& stroke)
        : x1(x1), y1(y1), x2(x2), y2(y2), width(width), stroke(stroke) {}

    std::string toSvg() const override {
        return "<line x1='" + std::to_string(x1) + "' y1='" + std::to_string(y1) +
               "' x2='" + std::to_string(x2) + "' y2='" + std::to_string(y2) +
               "' stroke='" + stroke + "' stroke-width='" + std::to_string(width) + "' />";
    }

private:
    float x1, y1, x2, y2, width;
    std::string stroke;
};

class SvgImage {
public:
    void addElement(const SvgElement& element) {
        elements.push_back(element.toSvg());
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        file << "<svg xmlns='http://www.w3.org/2000/svg' width='500' height='500' viewBox='0 0 500 500'>\n";
        for (const auto& element : elements) {
            file << element << "\n";
        }
        file << "</svg>";
    }

private:
    std::vector<std::string> elements;
};

int main() {
    SvgImage image;

    // Добавляем элементы, вдохновленные работой Эль Лисицкого
    image.addElement(Circle(250, 250, 40, "red")); // Красный круг
    image.addElement(Rect(100, 100, 80, 50, "black")); // Черный прямоугольник
    image.addElement(Line(150, 300, 350, 300, 5, "black")); // Черная линия
    image.addElement(Rect(200, 200, 150, 100, "white")); // Белый прямоугольник
    image.addElement(Circle(300, 150, 30, "black")); // Черный круг
    image.addElement(Rect(50, 350, 120, 60, "red")); // Красный прямоугольник
    // Добавьте дополнительные элементы по вашему усмотрению...

    image.saveToFile("lissitzky.svg");

    return 0;
}
