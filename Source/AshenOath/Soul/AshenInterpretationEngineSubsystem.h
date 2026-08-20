// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenInterpretationEngineSubsystem.generated.h"

UENUM(BlueprintType)
enum class EInterpretationPassType : uint8
{
	Integrative    UMETA(DisplayName = "Integrative Pass (Memory Weaving)"),
	Fragmentation  UMETA(DisplayName = "Fragmentation Pass (Whispering Void)")
};

USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenInterpretationContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Interpretation")
	FName SourceMemoryID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Interpretation")
	FText RawEventText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Interpretation")
	FText ContestedInterpretationText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Interpretation")
	float InterpretiveClarityRequired = 0.75f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInterpretationPassExecutedSignature, FName, MemoryID, EInterpretationPassType, PassType, bool, bClaritySucceeded);

/**
 * UAshenInterpretationEngineSubsystem
 *
 * Master abstraction layer governing the contest between integrative memory alignment 
 * and entropic narrative fragmentation (UMB-INT-001).
 */
UCLASS()
class ASHENOATH_API UAshenInterpretationEngineSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Executes a pass over a targeted memory from the Memory Palace
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Interpretation")
	void ExecuteInterpretationPass(FName MemoryID, EInterpretationPassType PassType);

	// Evaluates whether Kaelen's Interpretive Clarity invalidates a fragmenting whisper
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Interpretation")
	bool EvaluateInterpretiveClarity(float CurrentClarityScore, float Threshold);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Interpretation|Events")
	FOnInterpretationPassExecutedSignature OnInterpretationPassExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Interpretation")
	int32 TotalPassesExecuted = 0;
};
