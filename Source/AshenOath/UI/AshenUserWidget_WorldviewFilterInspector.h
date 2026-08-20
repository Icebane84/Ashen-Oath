// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_WorldviewFilterInspector.generated.h"

/**
 * UAshenUserWidget_WorldviewFilterInspector
 * UMG backing widget inspecting companion worldview filter text logs (Kaelen, Garrett, Serafina) for selected map nodes.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WorldviewFilterInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName InspectedNodeID;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayNodeWorldviewFilter(FName NodeID, FText KaelenLog, FText GarrettNote, FText SerafinaNote);
};
