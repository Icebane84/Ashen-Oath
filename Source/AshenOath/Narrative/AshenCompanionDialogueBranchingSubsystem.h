// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCompanionDialogueBranchingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionDialogueSelected, FName, CompanionID, FText, SelectedLine);

/**
 * UAshenCompanionDialogueBranchingSubsystem
 * World Subsystem selecting dynamic dialogue lines based on EEmpathicProfile and trust levels.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionDialogueBranchingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Narrative")
	FOnCompanionDialogueSelected OnDialogueSelected;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	FText SelectDynamicDialogueLine(FName CompanionID, uint8 EmpathicProfileEnum, float TrustLevel);
};
