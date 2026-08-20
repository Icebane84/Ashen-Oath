// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticArmorScuffModulatorComponent.generated.h"

/**
 * UAshenDiegeticArmorScuffModulatorComponent
 * Binds armor scuff & weathering parameters to IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticArmorScuffModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticArmorScuffModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetArmorScuffScalar() const { return ArmorScuffScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float ArmorScuffScalar = 0.0f;
};
