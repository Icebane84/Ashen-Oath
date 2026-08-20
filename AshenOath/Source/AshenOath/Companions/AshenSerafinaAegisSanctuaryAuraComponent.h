// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaAegisSanctuaryAuraComponent.generated.h"

/**
 * UAshenSerafinaAegisSanctuaryAuraComponent
 * Companion component emitting Serafina's holy aegis sanctuary aura mitigating physical & somatic damage.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAegisSanctuaryAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAegisSanctuaryAuraComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float SanctuaryAuraRadius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float DamageMitigationPercent = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void ActivateSanctuaryAura();
};
