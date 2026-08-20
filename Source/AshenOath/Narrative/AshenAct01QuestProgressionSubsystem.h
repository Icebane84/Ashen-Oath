// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenAct01QuestProgressionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAct01QuestStageAdvancedSignature, FName, NewQuestStageTag, bool, bIsAct01Complete);

/**
 * UAshenAct01QuestProgressionSubsystem
 *
 * Subsystem managing Act 01 objective tracking and stage progression (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API UAshenAct01QuestProgressionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Act01Quest")
	void AdvanceAct01QuestStage(FName StageTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Act01Quest|Events")
	FOnAct01QuestStageAdvancedSignature OnQuestStageAdvanced;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Act01Quest")
	FName CurrentQuestStage = FName(TEXT("Stage.ReachBlackwoodBridge"));
};
