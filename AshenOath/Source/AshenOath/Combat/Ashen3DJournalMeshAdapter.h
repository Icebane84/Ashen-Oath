// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Ashen3DJournalMeshAdapter.generated.h"

/**
 * UAshen3DJournalMeshAdapter
 * Modulates the 3D held field journal dynamic material instance (leather wear, gold foil leafing, and dry ink shading).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshen3DJournalMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshen3DJournalMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Visuals")
	float GoldFoilLeafGlow = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void UpdateJournalFoilLeafing(int32 TotalInkedRegions);
};
