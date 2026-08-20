// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPartyMoralResonanceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartyMoralAlignmentShiftedSignature, FName, MoralAlignmentTag, float, PartyMoraleMultiplier);

/**
 * UAshenPartyMoralResonanceSubsystem
 *
 * World Subsystem calculating moral alignment shifts across Kaelen, Garrett, and Serafina during quest resolutions.
 */
UCLASS()
class ASHENOATH_API UAshenPartyMoralResonanceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PartyMorale")
	void RegisterMoralChoiceResolution(FName MoralAlignmentTag, float AlignmentDelta);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PartyMorale|Events")
	FOnPartyMoralAlignmentShiftedSignature OnMoralAlignmentShifted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PartyMorale")
	float CalculatedPartyMoraleMultiplier = 1.0f;
};
