// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMemoryWeavingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryThreadWovenSignature, FName, MemoryID, int32, TotalThreadCount);

/**
 * UAshenMemoryWeavingSubsystem
 *
 * World Subsystem unlocking fragmented narrative memories at Heartstones via Memory Threads collected in Mindscape dungeons.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryWeavingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryWeaving")
	bool WeaveMemoryThread(FName MemoryID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|MemoryWeaving")
	int32 GetCollectedMemoryThreadCount() const { return CollectedThreads.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryWeaving|Events")
	FOnMemoryThreadWovenSignature OnMemoryThreadWoven;

private:
	TSet<FName> CollectedThreads;
};
