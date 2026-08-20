// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaRadiantPurgeAuraDirectorComponent.generated.h"

/**
 * UAshenSerafinaRadiantPurgeAuraDirectorComponent
 * Companion component directing Serafina's radiant purge aura field deployment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaRadiantPurgeAuraDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaRadiantPurgeAuraDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float RadiantPurgeAuraRadius = 750.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void DeployRadiantPurgeAura();
};
