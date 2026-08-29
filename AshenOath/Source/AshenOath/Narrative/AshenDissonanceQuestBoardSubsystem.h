// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenDissonanceQuestBoardSubsystem.generated.h"

/**
 * UAshenDissonanceQuestBoardSubsystem
 * 
 * Manages the generation, tracking, and branching resolution of dynamic psychological dissonance contracts.
 */
UCLASS()
class ASHENOATH_API UAshenDissonanceQuestBoardSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDissonanceQuestBoardSubsystem();

	/** Registers or generates a new dissonance contract */
	UFUNCTION(BlueprintCallable, Category = "Ashen|CSE|QuestBoard")
	void RegisterQuestContract(const FDissonanceQuestContract& Contract);

	/** Resolves a contract with the specified ideological outcome */
	UFUNCTION(BlueprintCallable, Category = "Ashen|CSE|QuestBoard")
	bool ResolveContract(FName ContractId, EQuestResolutionOutcome Outcome);

	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|QuestBoard")
	TArray<FDissonanceQuestContract> GetActiveContracts() const { return ActiveContracts; }

	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|QuestBoard")
	int32 GetResolvedContractCount() const { return ResolvedContracts.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|CSE|QuestBoard")
	FOnDissonanceQuestGenerated OnDissonanceQuestGenerated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|CSE|QuestBoard")
	FOnDissonanceQuestResolved OnDissonanceQuestResolved;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE|QuestBoard")
	TArray<FDissonanceQuestContract> ActiveContracts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|CSE|QuestBoard")
	TArray<FDissonanceQuestContract> ResolvedContracts;
};
