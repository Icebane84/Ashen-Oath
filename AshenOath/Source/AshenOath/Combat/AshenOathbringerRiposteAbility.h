// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenOathbringerRiposteAbility.generated.h"

/**
 * UAshenOathbringerRiposteAbility
 * Contextual riposte execution ability triggered during State.Combat.Staggered.
 * Synchronizes execution transforms, triggers trauma shake, applies 450.0 execution damage, and resets target poise.
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerRiposteAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenOathbringerRiposteAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Riposte")
	float RiposteExecutionDamage = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Riposte")
	float ExecutionSocketDistance = 120.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Riposte")
	FVector LastExecutionPosition = FVector::ZeroVector;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Riposte")
	bool ExecuteRiposte(AActor* TargetActor, bool bTargetStaggered);
};
