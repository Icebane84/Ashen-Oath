// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossDesecrationMeshAdapter.generated.h"

/**
 * UAshenBossDesecrationMeshAdapter
 * Modulates the dynamic material instance of boss skeletal meshes (armor cracks, glowing void veins, and phase 3 ash disintegration).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossDesecrationMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossDesecrationMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Visuals")
	float DesecrationVeinIntensity = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void UpdateBossDesecrationVisuals(EBossPhaseState Phase);
};
