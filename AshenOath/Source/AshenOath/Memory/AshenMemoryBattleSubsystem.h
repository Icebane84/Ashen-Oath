// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMemoryBattleSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryBattleStateChanged, FName, MemoryEchoID, bool, bVictory);

/**
 * UAshenMemoryBattleSubsystem
 * World Subsystem orchestrating the Memory Battle loop, spawning scaled psychological echoes from heaviest buffered imprints.
 */
UCLASS()
class ASHENOATH_API UAshenMemoryBattleSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Memory Battle")
	FOnMemoryBattleStateChanged OnMemoryBattleStateChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory Battle")
	bool bIsMemoryBattleActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory Battle")
	FName ActiveEchoID = NAME_None;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	bool InitiateMemoryBattle(FName EchoID, float ImprintWeight, bool bForcedCollapse);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	void ConcludeMemoryBattle(bool bPlayerWon);
};
