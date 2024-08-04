//
// Created by 18101 on 2024/8/4.
//
#include "Factory.h"

// 具体产品类实现
void ProductA::process() {
    if (strategy) {
        strategy->process();
    } else {
        std::cout << "Wrong ProductA." << std::endl;
    }
}

void ProductB::process() {
    if (strategy) {
        strategy->process();
    } else {
        std::cout << "Wrong ProductB." << std::endl;
    }
}

void ProductC::process() {
    if (strategy) {
        strategy->process();
    } else {
        std::cout << "Wrong ProductC." << std::endl;
    }
}

// 策略工厂类实现
std::unique_ptr<Strategy> StrategyFactory::createStrategy(const std::string& type) {
    if (type == "Heating") {
        return std::make_unique<HeatingStrategy>();
    } else if (type == "Cooling") {
        return std::make_unique<CoolingStrategy>();
    } else if (type == "Mixing") {
        return std::make_unique<MixingStrategy>();
    } else {
        return nullptr;
    }
}

// 工厂类实现
std::unique_ptr<Product> ProductFactory::createProduct(const std::string& type) {
    if (type == "ProductA") {
        return std::make_unique<ProductA>();
    } else if (type == "ProductB") {
        return std::make_unique<ProductB>();
    } else if (type == "ProductC") {
        return std::make_unique<ProductC>();
    } else {
        return nullptr;
    }
}
