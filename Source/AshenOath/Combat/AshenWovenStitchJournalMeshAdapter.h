// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWovenStitchJournalMeshAdapter.generated.h"

/**
 * UAshenWovenStitchJournalMeshAdapter
 * Modulates the 3D living field journal material instance, driving glowing golden embroidered stitches (0.0 to 3.0 glow) along the parchment spine.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWovenStitchJournalMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWovenStitchJournalMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float StitchEmissiveGlow = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateJournalStitchGlow(int32 ResolvedIncidentsCount);
};
