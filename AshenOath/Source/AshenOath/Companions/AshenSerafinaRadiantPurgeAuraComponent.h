// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaRadiantPurgeAuraComponent.generated.h"

/**
 * UAshenSerafinaRadiantPurgeAuraComponent
 * Companion component emitting Serafina's radiant purge aura cleansing nearby allies of status debuffs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaRadiantPurgeAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaRadiantPurgeAuraComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float RadiantPurgeRadius = 500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void EmitRadiantPurgePulse();
};
