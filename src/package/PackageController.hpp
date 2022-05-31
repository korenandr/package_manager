#ifndef PACKAGE_MANAGER_PACKAGE_PACKAGECONTROLLER_HPP
#define PACKAGE_MANAGER_PACKAGE_PACKAGECONTROLLER_HPP

#include "Package.hpp"


namespace ns
{

class PackageController final : public Package
{
public:
    explicit PackageController(const std::string& serializedDataPath = "");
    ~PackageController() override;

    PackageController(const PackageController&) = delete;
    PackageController& operator=(const PackageController&) = delete;

    PackageController(PackageController&&) = default;
    PackageController& operator=(PackageController&&) = default;

    OperationResult create(const std::string& name);

private:
 
    void serialize() const;
    void deserialize();

private:

    std::string _serializedDataPath;
};

}


#endif //PACKAGE_MANAGER_PACKAGE_PACKAGECONTROLLER_HPP
