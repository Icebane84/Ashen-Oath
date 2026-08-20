// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaRadiantPurgePincerDirectorComponent.generated.h"

/**
 * UAshenSerafinaRadiantPurgePincerDirectorComponent
 * Companion component directing Serafina's radiant purge pincer aura deployment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaRadiantPurgePincerDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaRadiantPurgePincerDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float RadiantPurgePincerRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void DeployRadiantPurgePincerAura();
};
