// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMemoryThreadSanctuarySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryThreadCollectedSignature, FName, ThreadID, int32, TotalThreadsCollected);

/**
 * UAshenMemoryThreadSanctuarySubsystem
 *
 * World Subsystem tracking narrative memory thread collection and unlocking hidden Sanctuary dialogues.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryThreadSanctuarySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryThreads")
	bool CollectMemoryThread(FName ThreadID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|MemoryThreads")
	int32 GetCollectedMemoryThreadCount() const { return CollectedThreads.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryThreads|Events")
	FOnMemoryThreadCollectedSignature OnMemoryThreadCollected;

private:
	TSet<FName> CollectedThreads;
};
