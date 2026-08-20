// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_OathRegistryJournal.h"

void UAshenUserWidget_OathRegistryJournal::RefreshOathJournal(const TArray<FOathRecord>& Oaths, float Burden)
{
	DisplayedOaths = Oaths;
	DisplayedBurden = Burden;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_OathRegistryJournal: Journal refreshed with %d oaths (Total Burden: %.2f)"), DisplayedOaths.Num(), DisplayedBurden);
}
