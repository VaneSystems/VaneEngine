#pragma once

#include <Vane/Core/Defines.hpp>
#include <Vane/Core/Mem/Allocator.hpp>

namespace Vane {
class StackAllocator : Allocator {
private:
    void* m_startPtr = nullptr;
    u_size m_offset;
public:
    StackAllocator(const u_size totalSize);
    virtual ~StackAllocator() override;
    virtual void* Allocate(u_size size, u8 alignment = 4) override;
    virtual void Free(void* ptr) override;
    virtual void Init() override;
    virtual void Reset();

    struct AllocationHeader {
        char padding;
    };
};
}