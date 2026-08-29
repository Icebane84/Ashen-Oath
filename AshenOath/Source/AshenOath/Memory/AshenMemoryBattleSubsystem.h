// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMemoryBattleSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryBattleStateChanged, FName, MemoryEchoID, bool, bVictory);

/**
 * UAshenMemoryBattleSubsystem
 * World Subsystem orchestrating the Memory Battle loop, spawning scaled psychological echoes from heaviest buffered imprints.
 * Concluding battles directly drives Graph unsealing, Sanity healing/damage, and Integration Debt pressure.
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

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory Battle")
	float ActiveEchoWeight = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	bool InitiateMemoryBattle(FName EchoID, float ImprintWeight, bool bForcedCollapse);

	/** Concludes active memory battle, resolving graph unsealing, sanity, and integration debt */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	void ConcludeMemoryBattle(bool bPlayerWon);

	/** Concludes active memory battle with explicit target combat character */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	void ConcludeMemoryBattleForCharacter(bool bPlayerWon, class AAshenCombatCharacter* TargetChar);
};
