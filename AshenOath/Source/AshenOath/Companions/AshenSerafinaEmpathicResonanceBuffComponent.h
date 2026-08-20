// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaEmpathicResonanceBuffComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmpathicResonanceBuffAppliedSignature, float, PostureRecoveryBonus, bool, bIsUninjuredResonanceActive);

/**
 * UAshenSerafinaEmpathicResonanceBuffComponent
 *
 * Component granting nearby party members +25% posture recovery when Serafina is uninjured (PRS-001 Serafina Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaEmpathicResonanceBuffComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaEmpathicResonanceBuffComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaBuff")
	float EvaluateEmpathicResonanceBuff(float SerafinaCurrentHealthPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaBuff|Events")
	FOnEmpathicResonanceBuffAppliedSignature OnResonanceBuffApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaBuff")
	float ActivePostureRecoveryBonus = 25.0f;
};
