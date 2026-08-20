// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCampfireRestManagerComponent.generated.h"

/**
 * UAshenCampfireRestManagerComponent
 * Manages rest cycles at campfires, restoring party stamina, healing trauma debt baselines, and initiating crafting modes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireRestManagerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCampfireRestManagerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Campfire")
	bool bIsRestingAtCampfire = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire")
	bool BeginCampfireRest();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire")
	void EndCampfireRest();
};
