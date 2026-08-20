// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenTacticalFlankInterceptDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTacticalFlankInterceptExecutedSignature, FName, InterceptTargetEnemyID, bool, bEQSBlindSpotProtected);

/**
 * UAshenTacticalFlankInterceptDirector
 *
 * Director altering Garrett's EQS to defend Kaelen's blind spots under Unbroken (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenTacticalFlankInterceptDirector : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TacticalFlank")
	void DirectGarrettTacticalFlank(FName FlankEnemyID, bool bIsKaelenUnbroken);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TacticalFlank|Events")
	FOnTacticalFlankInterceptExecutedSignature OnTacticalFlankExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|TacticalFlank")
	int32 TotalFlankInterceptsDirected = 0;
};
