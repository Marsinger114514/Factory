#include "Factory.h"

int main() {
    FactoryManager& manager = FactoryManager::getInstance();

    // 创建产品A并指定加热策略
    std::unique_ptr<Product> productA = manager.createProduct("ProductA");
    if (productA) {
        manager.assignStrategy(productA.get(), "Heating");
        productA->process();
    }

    // 创建产品B并指定冷却策略
    std::unique_ptr<Product> productB = manager.createProduct("ProductB");
    if (productB) {
        manager.assignStrategy(productB.get(), "Cooling");
        productB->process();
    }

    // 创建产品C并指定混合策略
    std::unique_ptr<Product> productC = manager.createProduct("ProductC");
    if (productC) {
        manager.assignStrategy(productC.get(), "Mixing");
        productC->process();
    }

    return 0;
}
