// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenNonBinaryMoralitySubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenMoralDisposition : uint8
{
	Protective       UMETA(DisplayName = "Protective"),
	Detached         UMETA(DisplayName = "Detached"),
	Vengeful         UMETA(DisplayName = "Vengeful"),
	SelfSacrificing  UMETA(DisplayName = "Self-Sacrificing"),
	Fatalistic       UMETA(DisplayName = "Fatalistic")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMoralDispositionShiftedSignature, EAshenMoralDisposition, DominantDisposition, float, VectorMagnitude);

/**
 * UAshenNonBinaryMoralitySubsystem
 *
 * World Subsystem interpreting player action tone across 5 nuanced dispositions instead of binary morality.
 */
UCLASS()
class ASHENOATH_API UAshenNonBinaryMoralitySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Morality")
	void RecordDispositionAction(EAshenMoralDisposition Disposition, float Intensity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Morality")
	EAshenMoralDisposition GetDominantDisposition() const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Morality|Events")
	FOnMoralDispositionShiftedSignature OnDispositionShifted;

private:
	TMap<EAshenMoralDisposition, float> DispositionVector;
};
