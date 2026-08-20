// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEcosystemPostProcessAdapter.generated.h"

/**
 * UAshenEcosystemPostProcessAdapter
 * Modulates post-process celestial bloom when near Star-Striders and temporal chromatic aberration near Aether-Weavers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEcosystemPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEcosystemPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyCelestialSanctuaryBloom(float Proximity);
};
