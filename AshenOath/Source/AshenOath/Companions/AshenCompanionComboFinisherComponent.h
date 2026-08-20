// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionComboFinisherComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnComboFinisherExecutedSignature, FName, CompanionID, float, FinisherDamage);

/**
 * UAshenCompanionComboFinisherComponent
 *
 * Synchronized finisher execution component triggering dual-character execute montages at low enemy health (<20%).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionComboFinisherComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionComboFinisherComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ComboFinisher")
	bool ExecuteDualComboFinisher(FName CompanionID, AActor* TargetEnemy);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ComboFinisher|Events")
	FOnComboFinisherExecutedSignature OnComboFinisherExecuted;
};
