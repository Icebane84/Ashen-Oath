// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticTorsoSootMeshAdapter.generated.h"

/**
 * UAshenSomaticTorsoSootMeshAdapter
 * Modulates Kaelen's skeletal mesh torso material parameters, scaling the ash-soot burn overlay permanently when choosing Wrath.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticTorsoSootMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSomaticTorsoSootMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float AshSootOverlayOpacity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void ApplyWrathSootBurn(float CorruptionIncrement);
};
