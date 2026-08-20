// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaSacredBarrierAuraComponent.generated.h"

/**
 * UAshenSerafinaSacredBarrierAuraComponent
 * Companion component emitting Serafina's sacred barrier aura absorbing incoming projectile and splash damage.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSacredBarrierAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaSacredBarrierAuraComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float SacredBarrierHealth = 250.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void DeploySacredBarrierAura();
};
