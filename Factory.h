//
// Created by 18101 on 2024/8/4.
//
#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>

// 抽象产品类
class Product {
public:
    virtual ~Product() = default;
    virtual void process() = 0;
    void setStrategy(class Strategy* strategy) {
        this->strategy = strategy;
    }
protected:
    class Strategy* strategy;
};

// 具体产品类
class ProductA : public Product {
public:
    void process() override;
};

class ProductB : public Product {
public:
    void process() override;
};

class ProductC : public Product {
public:
    void process() override;
};

// 抽象加工策略接口
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void process() = 0;
};

// 具体策略类
class HeatingStrategy : public Strategy {
public:
    void process() override {
        std::cout << "Heating." << std::endl;
    }
};

class CoolingStrategy : public Strategy {
public:
    void process() override {
        std::cout << "Cooling." << std::endl;
    }
};

class MixingStrategy : public Strategy {
public:
    void process() override {
        std::cout << "Mixing." << std::endl;
    }
};

// 策略工厂类
class StrategyFactory {
public:
    static std::unique_ptr<Strategy> createStrategy(const std::string& type);
};

// 工厂类
class ProductFactory {
public:
    static std::unique_ptr<Product> createProduct(const std::string& type);
};

// 工厂管理者类
class FactoryManager {
public:
    static FactoryManager& getInstance() {
        static FactoryManager instance;
        return instance;
    }

    std::unique_ptr<Product> createProduct(const std::string& type) {
        return ProductFactory::createProduct(type);
    }

    void assignStrategy(Product* product, const std::string& strategyType) {
        product->setStrategy(StrategyFactory::createStrategy(strategyType).release());
    }

private:
    FactoryManager() = default;
    FactoryManager(const FactoryManager&) = delete;
    FactoryManager& operator=(const FactoryManager&) = delete;
};

#endif // FACTORY_H

