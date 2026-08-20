// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaMasterPurgeAuraDirectorComponent.generated.h"

/**
 * UAshenSerafinaMasterPurgeAuraDirectorComponent
 * Companion component directing Serafina's pinnacle master purge aura deployment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaMasterPurgeAuraDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaMasterPurgeAuraDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float MasterPurgeAuraRadius = 900.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void DeployMasterPurgeAura();
};
