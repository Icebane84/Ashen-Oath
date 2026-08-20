// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaSacredBarrierPincerDirectorComponent.generated.h"

/**
 * UAshenSerafinaSacredBarrierPincerDirectorComponent
 * Companion component directing Serafina's sacred barrier pincer aura deployment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSacredBarrierPincerDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaSacredBarrierPincerDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float SacredBarrierPincerHealth = 350.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	void DeploySacredBarrierPincer();
};
