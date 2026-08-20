// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNullZoneSaveGameAdapter.generated.h"

/**
 * UAshenNullZoneSaveGameAdapter
 * Serializes discovered memory fragments and purified environmental anchor states to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNullZoneSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNullZoneSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveFragmentState(FName FragmentID, bool bConsumed);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveAnchorState(FName AnchorID, bool bConsecrated);
};
