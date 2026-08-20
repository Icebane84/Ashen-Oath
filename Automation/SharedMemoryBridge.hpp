// Copyright Ashen Oath Tactical RPG. All Rights Reserved.
// Standalone GUCA-001 Lock-Free Shared Memory Ring Buffer Contract

#pragma once

#include <cstdint>
#include <atomic>
#include <array>
#include <cstddef>

#pragma pack(push, 1)
struct alignas(128) FSoulStateVectorIPC {
    float Resolve{1.0f};             // Offset 0x00
    float Corruption{0.0f};          // Offset 0x04
    float Isolation{0.0f};           // Offset 0x08
    float IntegrationDebt{0.0f};     // Offset 0x0C
    float GarrettTrust{0.5f};        // Offset 0x10
    float SerafinaTrust{0.5f};       // Offset 0x14
    uint32_t RevisionEpoch{1};       // Offset 0x18
    uint8_t ReservedPadding[100]{0}; // Offset 0x1C -> Total: 128 Bytes
};
#pragma pack(pop)

static_assert(sizeof(FSoulStateVectorIPC) == 128, "IPC Struct must be exactly 128 bytes");

template<size_t Capacity = 64>
class alignas(128) TSharedMemoryRingBuffer {
public:
    static_assert((Capacity & (Capacity - 1)) == 0, "Capacity must be a power of 2");

    bool Enqueue(const FSoulStateVectorIPC& InState) {
        const uint64_t CurrentHead = Head.load(std::memory_order_relaxed);
        const uint64_t CurrentTail = Tail.load(std::memory_order_acquire);

        if (CurrentHead - CurrentTail >= Capacity) {
            return false; // Buffer Full
        }

        Buffer[CurrentHead & (Capacity - 1)] = InState;
        Head.store(CurrentHead + 1, std::memory_order_release);
        return true;
    }

    bool Dequeue(FSoulStateVectorIPC& OutState) {
        const uint64_t CurrentTail = Tail.load(std::memory_order_relaxed);
        const uint64_t CurrentHead = Head.load(std::memory_order_acquire);

        if (CurrentTail == CurrentHead) {
            return false; // Buffer Empty
        }

        OutState = Buffer[CurrentTail & (Capacity - 1)];
        Tail.store(CurrentTail + 1, std::memory_order_release);
        return true;
    }

    size_t Size() const {
        const uint64_t CurrentTail = Tail.load(std::memory_order_relaxed);
        const uint64_t CurrentHead = Head.load(std::memory_order_relaxed);
        return static_cast<size_t>(CurrentHead - CurrentTail);
    }

    bool IsEmpty() const { return Size() == 0; }

private:
    std::array<FSoulStateVectorIPC, Capacity> Buffer;
    alignas(64) std::atomic<uint64_t> Head{0};
    alignas(64) std::atomic<uint64_t> Tail{0};
};
